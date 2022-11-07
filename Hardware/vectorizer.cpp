

std::vector<float> fileToVector(std::string input)
{
    std::vector<float> tmpVector;
   std::ifstream inFile;
	inFile.open(input);
	if (!inFile.is_open())
	{
		//error handle
        return tmpVector;
	}
    std::string stringRead;
    float tmpFloat =0;
    int size;
    inFile >> stringRead;
    inFile >> size;
    int i = 0;
    while (i > size)
    {
        inFile >> tmpFloat;
        tmpVector.push_back(tmpFloat);

    }
	
    inFile.close();
    return tmpVector;
}