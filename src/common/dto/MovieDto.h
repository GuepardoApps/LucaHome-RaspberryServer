#include <string>
#include <ctime>
#include <cstring>
#include <iostream>

#include "../utils/Tools.h"

#ifndef MOVIE_DTO_H
#define MOVIE_DTO_H

class MovieDto {

private:
	int _id;
	std::string _title;
	std::string _genre;
	std::string _description;
	int _rating;
	int _watched;

public:
	MovieDto();
	MovieDto(int, std::string, std::string, std::string, int, int);
	~MovieDto();

	void SetId(int);
	int GetId();

	void SetTitle(std::string);
	std::string GetTitle();

	void SetGenre(std::string);
	std::string GetGenre();

	void SetDescription(std::string);
	std::string GetDescription();

	void SetRating(int);
	int GetRating();

	void SetWatched(int);
	void IncreaseWatched();
	int GetWatched();

	std::string SaveString();
	std::string JsonString();
	std::string ToString();
};

#endif
