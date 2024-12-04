#pragma once

#include <vulkan/vulkan_core.h>
#include <SDL3/SDL_video.h>

namespace SDLarria 
{
	class VulkanInstance 
	{
	public:
		VulkanInstance() = default;

		void Initialize(SDL_Window* window);
		void Destroy() const;

		VkPhysicalDevice GetPhysicalDevice() const { return m_PhysicalDevice; }
		VkDevice GetLogicalDevice() const { return m_LogicalDevice; }
		VkSurfaceKHR GetWindowSurface() const { return m_WindowSurface; }

		VkQueue GetRenderQueue() const { return m_Queue; }
		const uint32_t GetQueueFamilyIndex() const { return m_FamilyIndex; }

	private:
		VkSurfaceKHR m_WindowSurface = nullptr;

		VkInstance m_Instance = nullptr;
		VkDebugUtilsMessengerEXT m_DebugUtils = nullptr;
		VkPhysicalDevice m_PhysicalDevice = nullptr;
		VkDevice m_LogicalDevice = nullptr;

		VkQueue m_Queue = nullptr;
		uint32_t m_FamilyIndex = 0;

		friend class VulkanEngine;
	};
}