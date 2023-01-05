// Compile: g++ -lcurl -fpermissive main.cpp
#include <iostream>
#include "curl/curl.h"

// Removing redundant output
size_t ClearWrite(void *buffer, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

// Get code
long ResponseCode(std::string link)
{
    CURL *curl = curl_easy_init();
    if(curl) {
        CURLcode res;
        const char * linkConvert = link.c_str();
        curl_easy_setopt(curl, CURLOPT_URL, linkConvert);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, ClearWrite);
        res = curl_easy_perform(curl);
        
        if(res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            return response_code;
        }
        curl_easy_cleanup(curl);
        return 0;
    }
}

// Main
int main() {
    std::string what;
    std::cout << "\n  Enter name: ";
    std::cin >> what;
    std::cout << "  -----------------------------" << std::endl;
    const int SERVICES = 5; // Length array
    std::string services[SERVICES] = {"https://www.youtube.com/@", // Array services
    "https://vk.com/", "https://github.com/", "https://www.tumblr.com/", "https://ok.ru/"}; 

    // Array iteration
    for (int i = 0; i < SERVICES; i++) {
        long code = ResponseCode(services[i] + what);
    if (code == 404) {
        std::cout << "  " << services[i] << " | N/A." << std::endl;
    }
    else {
        std::cout << "  " << services[i] << " | Success!"<< std::endl;
    }
    }
    std::cout << "  -----------------------------" << std::endl << std::endl;
    
}