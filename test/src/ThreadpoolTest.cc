#include <gtest/gtest.h>

#include <limits>
#include <ThreadPool.hpp>
#include <iostream>

TEST(ThreadpoolTest, BaseTest)
{
	std::unique_ptr<ThreadPool> threadpool = std::make_unique<ThreadPool>(4u);

	std::future<int> waitObj    = threadpool->SubmitWork(std::function{[]()->int { return 8; }});
	std::future<void> waitObj1  = threadpool->SubmitWork(std::function{[]()->void {}});

	waitObj1.wait();
	waitObj.wait();

	EXPECT_EQ(waitObj.get(), 8) << "Values don't match.";
}
