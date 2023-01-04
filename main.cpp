#include <iostream>
#include "curl/curl.h"
#include <cstring>
using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
class Program
{

public:
	string what;
	void Print(string service, string status){
		cout << "  " << service << " | " << status << endl;
	}
	string AlgPro(string service, string username,int count1, int count2){
	CURL *curl;
	CURLcode res;
    string readBuffer;
	curl = curl_easy_init();
	string result = service + username;
	const char *resultConvert = result.c_str();
	if(curl) {
	curl_easy_setopt(curl, CURLOPT_URL, resultConvert);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
	res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	const char *bufferConvert = readBuffer.c_str();
	int count = strlen(bufferConvert);
	if (count < count1) {
		Print(service,"404 Not Found");
	}
	else if (count < count2) {
		Print(service,"Success");
	}
	}
	return readBuffer;	
	}
	string Alg(string service, string username,int count1){
	CURL *curl;
	CURLcode res;
    string readBuffer;
	curl = curl_easy_init();
	string result = service + username;
	const char *resultConvert = result.c_str();
	if(curl) {
	curl_easy_setopt(curl, CURLOPT_URL, resultConvert);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
	res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	const char *bufferConvert = readBuffer.c_str();
	int count = strlen(bufferConvert);
	if (count < count1) {
		Print(service,"404 Not Found");
	}
	else {
		Print(service,"Success");
	}
	}
	return readBuffer;	
	}
	
	void MainMenu(){
	cout << "\n  Enter username: ";
	cin >> what;
	cout << "  -------------------------------------\n";
	Alg("https://www.youtube.com/@",what,800);
	Alg("https://github.com/",what,800);
	cout << "  -------------------------------------\n\n";
	}	
};
int main()
{
	Program p;
	p.MainMenu();
	return 0;
}