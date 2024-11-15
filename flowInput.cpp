#include <fstream>
#include <string>

using namespace std;

class FlowInput {

    static const int DEFAULT_NUMBER_MAX_CHARACTERS_PER_READ = 2000;

    int numberMaxCharacteresPerRead;
    string contentBlock;
    ifstream file;

    void clearReadVariable() {
        this -> contentBlock.clear();
    }

    public:
        
        int blockNumberAnalyzed;
        string fileName;

        FlowInput(string fileName, int maxCharacteresPerRead = DEFAULT_NUMBER_MAX_CHARACTERS_PER_READ) {
            this -> numberMaxCharacteresPerRead = maxCharacteresPerRead;
            this -> blockNumberAnalyzed = 1;

            this -> fileName = fileName;

            file.open(this -> fileName);
        }

        ˜FlowInput() {
            this ->  closeFile();
        }

        void setMaxCharacteresPerRead(int newMaxCharacteres = DEFAULT_NUMBER_MAX_CHARACTERS_PER_READ) {
            this -> numberMaxCharacteresPerRead = newMaxCharacteres;
        }

        void closeFile() {
            this -> file.close();
        }

        bool isBlocksToBeRead() {return (this -> file.peek() != EOF);} // checks if there are blocks to be read by analyzing whether there is an end of file on the next read

        pair<int, string> ReadingBlock(int blockToBeRead = -1) {
            if(blockToBeRead < 1) blockToBeRead = this -> blockNumberAnalyzed;
            
            if(!file.is_open() or !isBlocksToBeRead()) 
                return {0, ""};

            clearReadVariable();
            contentBlock.reserve(this->numberMaxCharacteresPerRead);
            getline(this->file, this->contentBlock);
            return {this->contentBlock.size(), this->contentBlock};
        }
};