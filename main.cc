#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class PipeViewier {
public:
  PipeViewier();
  ~PipeViewier();

private:
  int bytes_data_count;
};

// Buffer length of 8 bytes
#define BUFFER_LENGTH 256

/*
Goal: Implement a simple version of Pipeviewier (A Tool that lets you observe
data throughput between two processes) The basic pseudocode is as follows
1. Read from STDIN to Buffer
2. check size of buffer and add to total data size
3. dump buffer contents to stdout
*/

int main() {

  string input = "";
  int total_length = 0;

  time_t timer_prev, timer_current;

  // Set the init timestamp
  time(&timer_prev);

  // Declare a Lambda
  auto test_func = [](int a){ std::cout<< "Hello " << a << std::endl;};
  test_func(1);

  // Basic 8-byte echo
  while (true) {
    getline(cin, input);
    if (input == "") {
      exit(1);
    } else {

      // Get timestamp
      time(&timer_current);
      double seconds = difftime(timer_current, timer_prev);
      timer_prev = timer_current;

      // Compute the data volume
      int input_length = input.length();
      total_length += input_length;

      // Log the data volume
      clog << total_length << " Bytes in " << seconds << " Seconds" << endl;

      // Finish transferring the data out
      cout << input << endl;
    }
  }
}
