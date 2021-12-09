#include "raylib.h"

class UIText
{
public:
    UIText(char* text, int size, Color colour);
    ~UIText() {};
    void Draw();
    void SetPosition(Vector2 pos, Vector2 offset);
    void SetText(char* text);
    void SetFontSize(int size);

private:
    Vector2 _position {0,0};
    int _fontSize {10};
    Color _fontColour {WHITE};
    char* _text {};


};