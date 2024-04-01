#include <gtest/gtest.h>

#include <limits>
#include <IThreadPool.hpp>
#include <ThreadPool.hpp>

TEST(ThreadpoolTest, BaseTest)
{
	std::unique_ptr<IThreadPool> threadpool = std::make_unique<ThreadPool>(4u);
}
