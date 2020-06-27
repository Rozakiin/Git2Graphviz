// *****************************************************************************
// * Name        : Git2Graphviz.h
// * Author      : Ruari Armstrong
// * Version     : 1.0
// * Copyright   : see LICENSE.md
// * Description : Creates a Graphviz file representing a Git repository's history.
// *****************************************************************************

#ifndef GIT2GRAPHVIZ_H_
#define GIT2GRAPHVIZ_H_

/* Program Version */
#define GIT2GRAPHVIZ_VERSION 1.0

#include <string>

/*******************************************************************************
 * Creates a Graphviz file representing a Git repository's history.
 ******************************************************************************/
class Git2Graphviz {
public:
	/***************************************************************************
	 * Makes directed graph of repository history between start and end commits,
	 * if start and end commits are empty makes digraph of whole repository.
	 *
	 * @param filename filename for Graphviz output file
	 * @param repo_path full path to repository directory
	 * @param start_commit_hash long hash value for the start commit
	 * @param end_commit_hash long hash value for the end commit
	 * @return 0 success or an error code
	 **************************************************************************/
	static int MakeGroundTruth(
			std::string filename,
			std::string repo_path,
			std::string start_commit_hash,
			std::string end_commit_hash);
	/** a public variable to store the version number of the class. */
	static constexpr double VersionNo = GIT2GRAPHVIZ_VERSION;
protected:
private:
};

#endif /* GIT2GRAPHVIZ_H_ */
