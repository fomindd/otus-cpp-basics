#include <high_scores.h>

int write_data(std::string name, int attempts)
{
    std::ofstream out_file{high_scores_filename, std::ios_base::app};
    if (!out_file.is_open()) {
        std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
        return -1;
    }

    out_file << name << ' ';
    out_file << attempts;
    out_file << std::endl;

    return 0;
}


int high_score()
{
    std::cout << std::endl;
    {
        std::ifstream in_file{high_scores_filename};
        if (!in_file.is_open()) {
            std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
            return -1;
        }

        std::cout << "High scores table:" << std::endl;

        std::string username;
        int high_score = 0;
        while (true) {

            in_file >> username;

            in_file >> high_score;

            in_file.ignore();

            if (in_file.fail()) {
                break;
            }
            std::cout << username << '\t' << high_score << std::endl;
        }
    }

    return 0;
}
