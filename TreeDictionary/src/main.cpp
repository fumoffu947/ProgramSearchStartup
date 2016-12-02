#include <iostream>
#include <filesystem>
namespace fs = std::experimental::filesystem;

int main() {

	std::cout << fs::current_path() << std::endl; // gets the current working directory
	fs::path a(".");
	std::cout << fs::absolute(a) << std::endl; // finds the path from root to the current relative path
	fs::path directory("a");
	bool dCreated = fs::create_directory(directory); // create file/directory return a bool for done or not
	std::cout << dCreated << std::endl;
	bool dRemaoved = false;
	if (dCreated) {
		dRemaoved = fs::remove(directory); // removes file/directory returns bool for done or not
	}
	std::cout << dRemaoved << std::endl;

	fs::space_info currentDir = fs::space(a); // gets the space avalible on the disk.......
	std::cout << ".        Capacity       Free      Available\n"
		<< "/dev:   " << currentDir.capacity / 1000000 << "   "
		<< currentDir.free/1000000 << "   " << currentDir.available / 1000000 << std::endl;

	std::cout << "a suitable temp directory " << fs::temp_directory_path() << std::endl; // returns a suitabla place for a tmp directory

	fs::directory_iterator dirIT = fs::directory_iterator(a);
	fs::directory_iterator pstart = fs::begin(dirIT);
	fs::directory_iterator pend = fs::end(dirIT);
	//while (pstart != pend) {
		//std::cout << "directory/file " << *pstart  << " : is_directory " << fs::is_directory(*pstart) << std::endl;
		//++pstart;
	//}
	for (fs::directory_iterator& p = pstart; p != pend; ++p) { // givs an iterator for the current directory so all the file can be traversed
		std::cout << "directory/file " << *p << " : is_directory " << fs::is_directory(*p) << std::endl;
	}

	std::string dummy;
	std::cin >> dummy;
	return 0;
}