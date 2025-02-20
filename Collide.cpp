#include <iostream>
#include <vector>
#include <raylib.h>
#include <raylib-cpp-utils.hpp>


using namespace std;

const int screenWidth = 800;
const int screenHeight = 600;

const int MAX_COLORS_COUNT = 21;

class Paddle {

public:
	Vector2 v{};
	int width{ 100 };
	int height = { 20 };
	int speed = 6;


	Paddle(int x, int y) {

		v.x = x;
		v.y = y;

		v.x -= width / 2;
		v.y -= height / 2;

	}

	void Draw() {
		DrawRectangle(v.x, v.y, width, height, { 255,0,0,125 });
	}

	Rectangle getPos() {
		return { v.x,v.y,(float)width , (float)height };
	}



	void Update() {

		if (IsKeyDown(KEY_RIGHT)) v.x += speed;
		if (IsKeyDown(KEY_LEFT)) v.x -= speed;
		if (IsKeyDown(KEY_UP)) v.y -= speed;
		if (IsKeyDown(KEY_DOWN)) v.y += speed;

		if (IsKeyDown(KEY_SPACE)) {
			cout << "fire";
		}
	}

};

int main()
{
	std::cout << "Hello World!\n";



	Color BackGroundColour = Color{ 155, 155, 155, 255 };

	SetTraceLogLevel(TraceLogLevel::LOG_NONE);

	InitWindow(screenWidth, screenHeight, "RAYGUNNED");
	SetTargetFPS(60);
	Paddle P(screenWidth / 2, screenHeight / 2);

	Rectangle boxA = { 10, GetScreenHeight() / 2.0f - 50, 200, 100 };
	Rectangle boxB = { GetScreenWidth() / 2.0f - 30, GetScreenHeight() / 2.0f - 30, 60, 60 };

	bool collision = false;



	while (WindowShouldClose() == false) {

		if (IsKeyDown(KEY_SPACE)) {
			DrawText("Welcome To My Game, Suckers !!!!", 18, GetScreenHeight() - 30, 20, GOLD);
			DrawFPS(10, 10);
		}

		BeginDrawing();

		P.Draw();
		P.Update();

		DrawRectangleRec(boxA, GOLD);
		DrawRectangleRec(boxB, BLUE);

		collision = CheckCollisionRecs(boxA, P.getPos());

		if (collision) {
			cout << 123;
		}


		EndDrawing();

		ClearBackground(BackGroundColour);
	}

	CloseWindow();
}

