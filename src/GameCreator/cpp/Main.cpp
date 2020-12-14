#include <iostream>
#include "GameCreator.h"
#include "CharacterCreator.h"
#include <string>
#include "FileHandler.h"
#include <cassert>
#include <cstdlib>
//#include<GLFW/glfw3.h>

void createfile(std::string location,std::string name, std::string extension) {

	std::ofstream ki;
	ki.open(location+name + '.' + extension);
	ki.close();
}
int main(int argc, char** argv) {
	//GLFWExample
	/*GLFWwindow* window;
	// Initialize the library 
	if (!glfwInit())
		return -1;

	// Create a windowed mode window and its OpenGL context 
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current 
	glfwMakeContextCurrent(window);

	// Loop until the user closes the window 
	while (!glfwWindowShouldClose(window))
	{
		// Render here 
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events 
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;*/
	//MainForOwnEngine
	std::string a;
	if (argc == 1) {
		//const std::string location = "D:\\SzE\\Programozassajat\\szerepjatek\\story\\";
		//const std::string extension = "txt";
		/*for (int i = 0; i <400 ; i++)
		{
			//createfile(location, std::to_string(i + 1), extension);
		}*/
		std::cout << "hiba\n";
	}
	else if (argc == 3) {
		srand(time(nullptr));
		CharacterCreator cc(12, 6, 6, 100);
		cc.create();
		Game::PlayerCharacter*p = cc.getPlayerCharacter();
		std::cout<<p->toStringCharacterStatus()<<'\n';
		FileHandler f(argv[1],argv[2]);
		f.readCSV();
		f.tokenizedLines();
		f.create();
		std::vector<Game::InformationAboutNextUnit*>info = f.getInfo();
		GameCreator gc(info);
		Game::Game*game = gc.createGameFromUnitVector();
		game->runGame(p);
		
	}
	std::getline(std::cin,a);
	//Coloring console
	/*system("Color 02");
	std::cout << "Hello world\n";
	system("Color 07");*/
	//getchar();*/
	return 0;
	


}
	