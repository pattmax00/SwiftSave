#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void backup(std::string backupDirs, std::string backupLocation) {
    std::ifstream backupDirsStream(backupDirs); // Opens backupDirs as file
    std::ifstream backupLocationStream(backupLocation); // Opens backupLocation as file

    // Sets backupLocationPath to the first line in backupLocationStream
    std::string backupLocationPath;
    getline(backupLocationStream, backupLocationPath);

    // Checks to make sure backupDirsStream and backupLocationStream are not empty.
    if (!backupDirsStream || !backupLocationStream) {
        std::cout << "Error: backup.dirs or backup.location do not exist or are empty" << std::endl;
        std::cout
                << "Please make sure that backup.dirs and backup.location are in the same location as this executable."
                << std::endl;
        std::cout << "backup.dirs must contain all the directories whose contents you want saved." << std::endl;
        std::cout
                << "backup.location must have its first line as the path where all backup.dirs' directories should be copied to."
                << std::endl;
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
    std::cout << "Backup started" << std::endl;
    backup("backup.dirs", "backup.location");
    return 0;
}
