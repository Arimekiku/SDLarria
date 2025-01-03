#pragma once

#include "vulkan_buffer.h"

#include <span>
#include <glm/glm.hpp>

namespace SDLarria
{
	struct Vertex
	{
		glm::vec3 Position;
		glm::vec3 Color;
	};

	class VulkanVertexArray
	{
	public:
		VulkanVertexArray() = default;
		VulkanVertexArray(std::span<uint32_t> indices, std::span<Vertex> vertices);
		~VulkanVertexArray();

		const std::vector<Vertex>& GetVertices() { return m_Vertices; }
		int GetIndexBufferSize() const { return m_Indices; }

		VulkanBuffer GetVertexBuffer() const { return m_VertexBuffer; }
		VulkanBuffer GetIndexBuffer() const { return m_IndexBuffer; }

	private:
		std::vector<Vertex> m_Vertices;
		int m_Indices;

		VulkanBuffer m_VertexBuffer;
		VulkanBuffer m_IndexBuffer;
	};
}
