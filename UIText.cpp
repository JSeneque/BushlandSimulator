#include "UIText.h"

UIText::UIText(char* text, int size, Color colour) :
    _text{text},
    _fontSize{size},
    _fontColour{colour} 
    { }


void UIText::Draw() 
{
    DrawText(_text, _position.x, _position.y, _fontSize, _fontColour);
}

void UIText::SetPosition(Vector2 pos, Vector2 offset)
{
    _position.x = pos.x + offset.x;
    _position.y = pos.y + offset.y;
}

void UIText::SetText(char* text)
{
    _text = text;
}


void UIText::SetFontSize(int size)
{
    _fontSize = size;
}