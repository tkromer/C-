/*
 * Creates a text file prgrammatically
 * by Tim Kromer
 */
 #include <fstream>
 using namespace std;

 int main()
 {
	 ofstream fileOut; // Declare variable
	 fileOut.open("output.txt"); // Have to open file before editing it

	 fileOut << "Hello" << endl;

	 fileOut.close();
	 return 0;
 }
