// *****************************************************************************
// * Name        : Git2Graphviz.cpp
// * Author      : Ruari Armstrong
// * Version     : 1.0
// * Copyright   : see LICENSE.md
// * Description : Creates a Graphviz file representing a Git repository's history.
// *****************************************************************************

#include <iostream>
#include <map>
#include "../lib/libgit2/include/git2.h"
#include "../lib/boost/libs/graph/include/boost/graph/adjacency_list.hpp"
#include "../lib/boost/libs/graph/include/boost/graph/graphviz.hpp"
#include "Git2Graphviz.hpp"


int Git2Graphviz::MakeGroundTruth(
		std::string filename,
		std::string repo_path,
		std::string start_commit_hash,
		std::string end_commit_hash)
{
	using namespace boost;
	typedef boost::adjacency_list<
			vecS,
			vecS,
			directedS,
			property<vertex_name_t, std::string>
	> Digraph;
	typedef boost::graph_traits<Digraph>::vertex_descriptor vertex_t;

	/* init variables */
	std::string commithash;
	std::string parenthash;
	uint numparents;
	int error;
	Digraph g;
	dynamic_properties dp;
	dp.property("hash", get(vertex_name, g));
	vertex_t commitvertex;
	vertex_t parentvertex;

	/* init libgit */
	error = git_libgit2_init();

	/* return if error initialising repo, print error */
	//https://libgit2.org/docs/guides/101-samples/
	if (error <= 0)
	{
		const git_error *e = git_error_last();
		std::cerr << "Error " << error << "/" << e->klass << ": " << e->message	<< "\n";
		return error;
	}


	/* open repo */
	const char *REPO_PATH = repo_path.c_str();
	git_repository *repo = nullptr;
	error = git_repository_open(&repo, REPO_PATH);

	/* return if error opening repo, print error */
	if (error != 0)
	{
		const git_error *e = git_error_last();
		std::cerr << "Error " << error << "/" << e->klass << ": " << e->message	<< "\n";
		return error;
	}


	/* create revision walker */
	git_revwalk *walker = nullptr;
	error = git_revwalk_new(&walker, repo);

	/* return if error allocating new revision walker, print error */
	if (error != 0)
	{
		const git_error *e = git_error_last();
		std::cerr << "Error " << error << "/" << e->klass << ": " << e->message	<< "\n";
		return error;
	}


	/* sort by chronological order */
	error = git_revwalk_sorting(walker, GIT_SORT_NONE);

	/* return if error changing sorting mode, print error */
	if (error != 0)
	{
		const git_error *e = git_error_last();
		std::cerr << "Error " << error << "/" << e->klass << ": " << e->message	<< "\n";
		return error;
	}

	/* set range for walker */
	if (start_commit_hash == "" && end_commit_hash == "")
	{
		/* start from HEAD */
		error = git_revwalk_push_head(walker);
		std::cout << "range: All \n";
	}
	else
	{
		std::string range = start_commit_hash + ".." + end_commit_hash;
		std::cout << "range: " << range << "\n";
		error = git_revwalk_push_range(walker, range.c_str());
	}
	/* return if error pushing range to walker, print error */
	if (error != 0 )
	{
		const git_error *e = git_error_last();
		std::cerr << "Error " << error << "/" << e->klass << ": " << e->message	<< "\n";
		return error;
	}


	/* walk the walk */
	git_oid oid;

	while (!git_revwalk_next(&oid, walker))
	{
		/* get the current commit */
		git_commit *commit = nullptr;
		error = git_commit_lookup(&commit, repo, &oid);

		/* return if error looking up commit, print error */
		if (error != 0)
		{
			const git_error *e = git_error_last();
			std::cerr << "Error " << error << "/" << e->klass << ": " << e->message	<< "\n";
			return error;
		}


		/* add commit vertex */
		commithash = git_oid_tostr_s(&oid);
		commitvertex = boost::add_vertex(commithash, g);

		/* get number of parents for commit */
		numparents = git_commit_parentcount(commit);

		for (uint i = 0; i < numparents; i++)
		{
			/* add parent vertex */
			parenthash = git_oid_tostr_s(git_commit_parent_id(commit, i));
			parentvertex = boost::add_vertex(parenthash, g);
			/* add commit:parent edge to graph */
			boost::add_edge(commitvertex, parentvertex, g);
		}
		/* free the commit */
		git_commit_free(commit);
	}

	/* clean up */
	git_revwalk_free(walker);
	git_repository_free(repo);

	error = git_libgit2_shutdown();

	/* return if error shutting down, print error */
	if (error < 0)
	{
		const git_error *e = git_error_last();
		std::cerr << "Error " << error << "/" << e->klass << ": " << e->message	<< "\n";
		return error;
	}

	std::ofstream outfile;
	try
	{
		outfile.open(filename+".gv");
	}
	catch(std::ifstream::failure &e)
	{
		std::cerr << "Exception opening \n";
		std::cerr << e.code() << "\n";
		//return e.code();
		return -1; //FIXME tempfix
	}
	write_graphviz_dp(outfile, g, dp, std::string("hash"));
	std::cout << "finished writing " << filename << ".gv\n";
	return 0;
}


