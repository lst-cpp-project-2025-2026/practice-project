#include "raylib.h"

// Structure to hold properties of a draggable/display box
typedef struct Box {
  Rectangle rect;
  Color outlineColor;
  Color fillColor;
  const char *text;
  int fontSize;
  Color textColor;
} Box;

// Function to draw a single Box structure, making it look hollow
void DrawHollowBox(Box box) {
  const int outlineThickness = 2;

  // 1. Draw the outline (using the box's dimensions and outline color)
  DrawRectangleRec(box.rect, box.outlineColor);

  // 2. Draw the inner filling (using a slightly smaller rectangle and the fill
  // color) We use RAYWHITE here to match the background for a true "hollow"
  // look.
  DrawRectangle(box.rect.x + outlineThickness, box.rect.y + outlineThickness,
                box.rect.width - 2 * outlineThickness,
                box.rect.height - 2 * outlineThickness,
                RAYWHITE); // Assuming the background is RAYWHITE

  // 3. Draw the text inside the box, centered
  int textWidth = MeasureText(box.text, box.fontSize);
  int textX = box.rect.x + (box.rect.width - textWidth) / 2;
  int textY = box.rect.y + (box.rect.height - box.fontSize) / 2;

  DrawText(box.text, textX, textY, box.fontSize, box.textColor);
}

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Raylib Git Practice - Modular Boxes");

  SetTargetFPS(60);

  const char *headerText = "Hello! Your task is to add a box below.";
  const int headerFontSize = 20;

  // --- Modular Box Initialization ---

  // Initialize the first box (Joe Doe)
  Box BilalBox = {
      .rect = {20, 60, 150, 100},
      .outlineColor = DARKGRAY,
      .fillColor =
          RAYWHITE, // Not strictly used by DrawHollowBox but good practice
      .text = "Bilal",
      .fontSize = 18,
      .textColor = DARKGRAY};
  Box AdilBox = {
      .rect = {180, 60, 150, 100},
      .outlineColor = DARKGRAY,
      .fillColor = RAYWHITE, 
      .text = "Adil",
      .fontSize = 18,
      .textColor = DARKGRAY};

  while (!WindowShouldClose()) {
    // Calculate header position
    int textWidth = MeasureText(headerText, headerFontSize);
    int xPosition = (screenWidth - textWidth) / 2;

    BeginDrawing();

    ClearBackground(RAYWHITE);

    // Draw header text
    DrawText(headerText, xPosition, 30, headerFontSize, LIGHTGRAY);

    // Draw the modular box
    DrawHollowBox(BilalBox);
    DrawHollowBox(AdilBox);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}