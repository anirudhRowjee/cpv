#include "ringbuffer.h"

RingBuffer::RingBuffer(int max_cap) {
  // Ensure that the mutex is locked as we construct it
  const std::lock_guard<std::mutex> lock(ringbuf_mutex);

  max_capacity = max_cap;
  int tracker = max_cap;

  Node *starter_node = new Node;
  starter_node->next = starter_node; // Ouroboros?
  tracker--;

  ROOT = starter_node;
  HEAD = starter_node;
  TAIL = starter_node;

  // Keep adding nodes
  while (tracker != 0) {
    Node *current_node = new Node;
    current_node->next = HEAD;
    TAIL->next = current_node;
    HEAD = current_node;
    tracker--;
  }
};

RingBuffer::~RingBuffer() {
  // Ensure that the mutex is locked as we construct it
  const std::lock_guard<std::mutex> lock(ringbuf_mutex);
  Node *current_node = ROOT;
  Node *next_node = ROOT;

  // Free nodes one by one until they're all gone
  while (current_node != nullptr) {
    // feel like this might panic
    next_node = current_node->next;
    delete current_node;
    current_node = next_node;
  }
}

void RingBuffer::_debug_stringdump(){};

RingBufferOperationStatus RingBuffer::Pull(int *value) {
  return RingBufferOperationStatus::PULL_SUCCESS;
};

RingBufferOperationStatus RingBuffer::Push(int *value) {
  return RingBufferOperationStatus::PUSH_SUCCESS;
};

int RingBuffer::GetMaxCapacity() { return max_capacity; };
