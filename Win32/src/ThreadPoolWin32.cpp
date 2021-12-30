#include <ThreadPoolWin32.hpp>
#include <functional>

void ThreadPoolWin32::Create(std::uint32_t threadCount) noexcept {
	InitializeThreadpoolEnvironment(&m_callbackEnv);
	m_threadPool = CreateThreadpool(nullptr);

	SetThreadpoolThreadMaximum(m_threadPool, threadCount);
	SetThreadpoolThreadMinimum(m_threadPool, 1u);

	m_cleanUpGroup = CreateThreadpoolCleanupGroup();

	SetThreadpoolCallbackPool(&m_callbackEnv, m_threadPool);
	SetThreadpoolCallbackCleanupGroup(&m_callbackEnv, m_cleanUpGroup, nullptr);
}

void ThreadPoolWin32::CleanUp() noexcept {
	CloseThreadpoolCleanupGroupMembers(m_cleanUpGroup, FALSE, nullptr);
	CloseThreadpoolCleanupGroup(m_cleanUpGroup);
	CloseThreadpool(m_threadPool);
}

void ThreadPoolWin32::SubmitWork(void* workFunction) {
	SubmitThreadpoolWork(CreateThreadpoolWork(
		ThreadPoolWin32::WorkCallBack, workFunction, &m_callbackEnv
	));
}

void ThreadPoolWin32::WorkCallBack(
	PTP_CALLBACK_INSTANCE instance,
	PVOID parameter,
	PTP_WORK work
) {
	std::function<void()>& callBack = *reinterpret_cast<std::function<void()>*>(parameter);

	callBack();
}