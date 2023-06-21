#include <iostream>
#include <fstream>
#include <string>

const std::string high_scores_filename = "high_scores.txt";

int high_score();
int write_data(std::string name, int attempts);
