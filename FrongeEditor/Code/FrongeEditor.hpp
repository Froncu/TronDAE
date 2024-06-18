#if not defined FRONGE_EDITOR_HPP
#define FRONGE_EDITOR_HPP

#include "Fronge.hpp"

namespace fro
{
	class FrongeEditor final : public Application
	{
	public:
		FrongeEditor();
		FrongeEditor(FrongeEditor const&) = default;
		FrongeEditor(FrongeEditor&&) noexcept = default;

		virtual ~FrongeEditor() override = default;

		FrongeEditor& operator=(FrongeEditor const&) = default;
		FrongeEditor& operator=(FrongeEditor&&) noexcept = default;

		virtual void run() override;

	private:
		EventListener<> mOnMainWindowCloseEvent
		{
			[this]()
			{
				mIsRunning = false;
			}
		};

		EventListener<Event&> mOnEvent
		{
			[this](auto&& event)
			{
				mLayerStack.onEvent(event);
			}
		};

		Window mMainWindow{ "Fronge Editor", 1280, 720 };
		LayerStack mLayerStack{};

		bool mIsRunning{ true };
	};
}

#endif