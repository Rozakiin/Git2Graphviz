// *****************************************************************************
// * Name        : main.cpp
// * Author      : Ruari Armstrong
// * Version     : 1.0
// * Copyright   : see LICENSE.md
// * Description : Main file of Git2Graphviz.
// *****************************************************************************

#include <iostream>
#include "boost/program_options.hpp"
namespace po = boost::program_options;

#include "Git2GraphvizLibrary/Git2Graphviz.hpp"

/*******************************************************************************
 * main.
 *
 * @param argc number of arguments passed
 * @param argv[] array of arguments
 * @return 0 success or an error code
 ******************************************************************************/
int main(int argc, char *argv[])
{
	/* Using boost/program_options to parse command line options */

	/* Declare variable names for args to be saved to */
	std::string filename;
	std::string repo_path;
	std::string start_commit_hash;
	std::string end_commit_hash;
	std::string input_file_path;

	try
	{
		/* Declare the supported options */
		po::options_description desc{"Allowed Options"};
		desc.add_options()
				("help", "prints usage information")
				("version","prints version of program")
				("repo,r", po::value<std::string>(&repo_path)->required(),"repository local path")
				("start,s", po::value<std::string>(&start_commit_hash)->default_value(""),"start commit hash")
				("end,e", po::value<std::string>(&end_commit_hash)->default_value(""),"end commit hash")
				("file,f", po::value<std::string>(&input_file_path),"path to file containing list of commits to compare(TODO)")//TODO
				("output-file,o", po::value<std::string>(&filename)->default_value("Git2Graphviz"),"output file name")
		;

		po::positional_options_description p;
		/* 1st arg with no option name treat as output-file option */
		p.add("output-file", 1);

		po::variables_map vm;
		po::store(po::command_line_parser(argc, argv).
				options(desc).positional(p).run(), vm);

		if (vm.count("help"))
		{
			std::cout << desc << '\n';
			return 1;
		}

		if (vm.count("version"))
		{
			std::cout << "Git2Graphviz Version: " << Git2Graphviz::VersionNo << '\n';
			return 1;
		}

		/* called after help and version to stop required option exception being thrown */
		po::notify(vm);

		/* Print out options being ran */
		std::cout << "Attempting to run with options:\n"
				<< "Repository Path: " << repo_path << "\n"
				<< "Start Hash: " << start_commit_hash << "\n"
				<< "End Hash: " << end_commit_hash << "\n"
				<< "List of Commits Path: " << input_file_path << "\n"
				<< "Output File: " << filename << "\n" ;

		int error = Git2Graphviz::MakeGroundTruth(
				filename,
				repo_path,
				start_commit_hash,
				end_commit_hash);
		if (error != 0 )
		{
			std::cerr << "Error occurred during execution \n";
			std::cerr << "Error: " << error << "\n";
			return -1;
		}
	}
	catch (const po::error &ex)
	{
		std::cerr << ex.what() << '\n';
		return -1;
	}

	return 0;
}


