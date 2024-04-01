#include <gtest/gtest.h>

#include <limits>
#include <ThreadPool.hpp>

TEST(ThreadpoolTest, BaseTest)
{
	std::unique_ptr<ThreadPool> threadpool = std::make_unique<ThreadPool>(4u);
}
