#include "gtest/gtest.h"
#include "Git2GraphvizLibrary/Git2Graphviz.hpp"
#include "git2.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

TEST(Git2GraphvizTests, DemonstrateGTestMacros) 
{
    EXPECT_TRUE(true);
}


TEST(Git2GraphvizTests, ReturnVersionNo)
{
    ASSERT_DOUBLE_EQ(Git2Graphviz::VersionNo, 1.0);
}

TEST(Git2GraphvizTests, fulltestrepo)
{
    /* using https://github.com/libgit2/libgit2/blob/master/examples/clone.c */
    git_repository *cloned_repo = NULL;
	git_clone_options clone_opts = GIT_CLONE_OPTIONS_INIT;
    const char *url = "https://github.com/libgit2/TestGitRepository.git";
	const char *path = "C:/Users/Ru/Documents/Work/Projects/CompareCommits/tests";
	int error;
    std::cout << url << "\n";
    std::cout << path << "\n";

    /* init repo */
    // git_repository *repo = NULL;
    // error = git_repository_init(
    //     &repo,                // output
    //     "./",                   // path
    //     false);               // bare?

	/* Do the clone */
    // error = git_clone(&cloned_repo, url, path, &clone_opts);
    // if (error != 0) {
	// 	const git_error *err = git_error_last();
	// 	if (err) printf("ERROR %d: %s\n", err->klass, err->message);
	// 	else printf("ERROR %d: no detailed info\n", error);
	// }
    // git_repository_free(cloned_repo);

    /* Make Ground Truth of cloned test repo */
    //Git2Graphviz::MakeGroundTruth("test", "TestGitRepository", "", "");

    /* Remove cloned test repo */
    //std::filesystem::remove_all("TestGitRepository"); // Deletes one or more files recursively.

    // /* Write example test file to compare */
    // std::ofstream testexample ("testexample.gv");
    // if (testexample.is_open())
    // {
    //     testexample << "This is a line.\n";
    //     testexample << "This is another line.\n";
    //     testexample.close();
    // }
    // else std::cerr << "Unable to open file";

    // /* Read test file */
    // std::string testline;
    // std::string testexampleline;
    // std::ifstream testfile ("test.gv");
    // std::ifstream testexamplefile ("testexample.gv");
    // if (testfile.is_open() && testexamplefile.is_open())
    // {
    //     while ( getline (testfile,testline) )
    //     {
    //         std::cout << testline << '\n';
    //         getline (testexamplefile,testexampleline);
    //         ASSERT_STREQ(testline.c_str(), testexampleline.c_str());
    //     }
    //     testfile.close();
    //     testexamplefile.close();
    // }
    // else std::cerr << "Unable to open file"; 
}