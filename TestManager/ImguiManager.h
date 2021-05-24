#ifndef _IMGUI_H
#define _IMGUI_H

#pragma once
#include "GL/glew.h"
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"
#include "imgui_internal.h"
#include <filesystem>
#include "ImGuiManager/imfilebrowser.h"
#include <iostream>
#include "UtilManager/UtilManager.h"
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <math.h>

#include "Utils/OBJLoader.h"
#include "Simulation/SimulationModel.h"
#include "Utils/FileSystem.h"
#include "Simulation/Simulation.h"

#define BIT(x) (1 << x)
#define PI std::atan(1.0)*4

class ImguiManager
{
public:
	ImguiManager();
	~ImguiManager();

	GLFWwindow* m_window;
	ImGui::FileBrowser m_fileDialog;
	ImVec4 m_clear_color;
	ImGuiIO* m_io;
	int m_w, m_h;
	std::string m_dirPath;

	int m_filetreeitem_current_idx;
	std::string m_filetree_current_item;
	std::string m_filetree_double_clicked_item;
	std::vector<std::string> m_filetreeitems;

	unsigned int m_fbo_texture;
	unsigned int m_fbo_depth;
	unsigned int m_fbo;
	GLuint m_shaderProgram;

	std::map<std::string, int> m_map_filetree_rigidbody;
	static int m_key_count;

	Eigen::Vector3f translation;

public:
	void Initialize(GLFWwindow* window);
	void StartFrame();
	void Render();
	void Cleanup();
	void ItemRowsBackground(float lineHeight, const ImColor& color);
	std::pair<bool, uint32_t> DirectoryTreeViewRecursive(const std::filesystem::path& path, uint32_t* count, int* selection_mask);
	void showDirectoryTree(std::string directoryPath);
	void loadObj(const std::string& filename, PBD::VertexData& vd, Utilities::IndexedFaceMesh& mesh, const Vector3r& scale);
	void addRigidbody(std::string fName);

	void createMainMenuBar();
	void createLeftSideMenu();
	void createRightSideMenu();
	void createCenterMenu();
	void createBottomMenu();
	void createFileDialogBtn();

	void fbo_init();
	void fbo_bind();
	void fbo_unbind();
	void fbo_cleanup();
	void draw();
};
#endif