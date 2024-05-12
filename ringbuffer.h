// Ringbuffer: Header file

#include <mutex>
enum RingBufferOperationStatus {
  PUSH_SUCCESS,
  PULL_SUCCESS,
  PUSH_FAIL,
  PULL_FAIL,
};

class RingBuffer {
  struct Node {
    int x;
    Node *next;
  };

public:
  // Constructor that initializes the Ringbuffer
  RingBuffer(int maxcap = 1);
  // Destructor
  ~RingBuffer();
  // "Write to the channel"; Returns status in int
  RingBufferOperationStatus Push(int *value);
  // "Read from the channel"
  RingBufferOperationStatus Pull(int *value);
  // Get max Capacity
  int GetMaxCapacity();
  void _debug_stringdump();

private:
  int max_capacity; // Maximum Capacity of the ringbuffer
  Node *HEAD;       // Pointer to the current HEAD of the ringbuffer queue
  Node *TAIL;       // Pointer to the current tail of the ringbuffer queue
  Node *ROOT;       // Fixed pointer to the root of the ringbuffer
  bool isfull;      // Boolean indicator to tell if the list is full
  std::mutex ringbuf_mutex; // Mutex for concurrent access
};
