#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

std::string backupLocationPath;

// Sets all global variables according to backup.conf
void loadConf(std::string backupConf) {
    std::ifstream backupLocationStream(backupConf); // Opens backupConf as file
    getline(backupLocationStream, backupLocationPath);
}

void backup(std::string backupDirs, std::string backupLocationPath) {
    std::ifstream backupDirsStream(backupDirs); // Opens backupDirs as file

    // Checks to make sure backupDirsStream is not empty.
    if (!backupDirsStream) {
        std::cout << "Error: backup.dirs does not exist or is empty" << std::endl;
        std::cout << "Please make sure that backup.dirs is in the same location as this executable." << std::endl;
        std::cout << "backup.dirs must contain all the directories whose contents you want saved." << std::endl;
    } else {
        // Goes through every line in backupDirsStream, sets that value to line, and saves that path to backupLocationPath
        for (std::string line; getline(backupDirsStream, line);) {
            std::cout << "Copying: " << line << " to " << backupLocationPath << std::endl;
            fs::copy(line, backupLocationPath, fs::copy_options::recursive | fs::copy_options::update_existing);
            std::cout << "Finished backing up: " << line << std::endl;
        }
        std::cout << "Finished backup with no errors." << std::endl;
    }
}

int main() {
    loadConf("backup.conf");
    std::cout << "Backup started" << std::endl;
    backup("backup.dirs", backupLocationPath);
    return 0;
}
