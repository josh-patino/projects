#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

int main() {
    std::string votes_input;
    std::cout << "Enter the NFL team votes (space-separated): ";
    std::getline(std::cin, votes_input);

    std::istringstream iss(votes_input);
    std::string vote;
    std::map<std::string, int> team_vote_counts;

    // Split the input string into a list of votes
    while (iss >> vote) {
        team_vote_counts[vote]++;
    }

    // Create a vector to store team names for custom ordering
    std::vector<std::string> custom_order = {
        "BEARS", "LIONS", "PACKERS", "VIKINGS",
        "COMMANDERS","COWBOYS","EAGLES","GIANTS",
        "BUCCANEERS","FALCONS","PANTHERS","SAINTS",
        "49ERS","CARDINALS","RAMS","SEAHAWKS",
        "BENGALS","BROWNS","RAVENS","STEELERS",
        "BILLS","DOLPHINS","JETS","PATRIOTS",
        "COLTS","JAGUARS","TEXANS","TITANS",
        "BRONCOS","CHARGERS","CHIEFS","RAIDERS",
    };

    // Output the team names and their vote counts in custom order
    for (const std::string& team : custom_order) {
        int count = team_vote_counts[team];
        std::cout << "Team: " << team << ", Votes: " << count << std::endl;
    }

    return 0;
}
