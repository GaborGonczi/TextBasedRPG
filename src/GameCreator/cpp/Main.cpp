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
	/*if (argc == 1) {
		//const std::string location = "D:\\SzE\\Programozassajat\\szerepjatek\\story\\";
		//const std::string extension = "txt";
		/*for (int i = 0; i <400 ; i++)
		{
			//createfile(location, std::to_string(i + 1), extension);
		}
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



	std::vector<std::string> r{ "startUnit", "R", "1", "1.txt", "startWhereAbleToNext", "10", "37", "29", "50", "60", "endWhereAbleToNext", "startItems", "startItem", "item1", "10", "5", "alma", "2", "endItem", "endItems", "startShopkeeper", "-", "-", "startArmor", "-", "-", "-", "endArmor", "startWeapon", "-", "-", "-", "endWeapon", "-", "-", "-", "-", "startSentences", "-", "-", "-", "endSentences", "startSentencesCnt", "0", "endSentenceCnt", "endShopKeeper", "startEnemies", "startEnemy", "-", "-", "-", "-", "-", "startArmor", "-", "-", "-", "endArmor", "startWeapon", "-", "-", "-", "endWeapon", "-", "-", "-", "-", "endEnemy", "endEnemies", "-", "-", "endUnit" };
	std::vector<std::string>f{ "startUnit", "F", "37", "37.txt", "startWhereAbleToNext", "2", "44", "100", "160", "3", "endWhereAbleToNext", "startItems", "startItem", "-", "-", "-", "-", "-", "endItem", "endItems", "startShopkeeper", "-", "-", "startArmor", "-", "-", "-", "endArmor", "startWeapon", "-", "-", "-", "endWeapon", "-", "-", "-", "-", "startSentences", "-", "-", "-", "endSentences", "startSentencesCnt", "0", "endSentenceCnt", "endShopKeeper", "startEnemies", "startEnemy", "Alabardos", "10", "12", "4", "500", "startArmor", "Pancel", "2", "1", "endArmor", "startWeapon", "Fegyver", "4", "0", "endWeapon", "1", "2", "2", "8", "endEnemy", "endEnemies", "13", "13", "endUnit" };
	std::vector<std::string>s{ "startUnit", "S", "20", "1.txt", "startWhereAbleToNext", "2", "3", "4", "5", "6", "endWhereAbleToNext", "startItems", "startItem", "item2", "20", "20", "Gyemantkard", "1", "endItem", "endItems", "startShopkeeper", "Soher", "30000", "startArmor", "ar", "0", "0", "endArmor", "startWeapon", "we", "0", "0", "endWeapon", "100000", "200000", "300000", "400000", "startSentences", "-", "-", "-", "endSentences", "startSentencesCnt", "0", "endSentenceCnt", "endShopKeeper", "startEnemies", "startEnemy", "-", "-", "-", "-", "-", "startArmor", "-", "-", "-", "endArmor", "startWeapon", "-", "-", "-", "endWeapon", "-", "-", "-", "-", "endEnemy", "endEnemies", "-", "-", "endUnit" };

	FileHandler file("alma", "korte0");
	std::vector<Game::InformationAboutNextUnit*>printable;
	printable.push_back(file.createMember(r));
	printable.push_back(file.createMember(f));
	printable.push_back(file.createMember(s));
	GameCreator gc(printable);
	Game::Game*game = gc.createGameFromUnitVector();
	game->print();
	6
	return 0;
	


}
	