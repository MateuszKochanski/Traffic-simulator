#pragma once
class CZnak
{
	
	char typ; // 0'U' - ustąp perwszeństwo, 1'P' - pierwszeństwo przejazdu,2'R' - rondo
public:
	CZnak(char); 
	char getTyp();
};

