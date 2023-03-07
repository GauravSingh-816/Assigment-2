#include "Single_Linked_List.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    head = new Node(item, head);
    if (tail == nullptr) tail = head;
    ++num_items;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (tail == nullptr) {
        head = new_node;
        tail = new_node;
    }
    else {
        tail->next = new_node;
        tail = new_node;
    }
    ++num_items;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) throw logic_error("pop_front() empty list");
    Node* old_head = head;
    head = head->next;
    delete old_head;
    --num_items;
    if (num_items == 0) tail = nullptr;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (empty()) throw logic_error("pop_back() empty list");
    if (num_items == 1) {
        delete tail;
        head = nullptr;
        tail = nullptr;
        num_items = 0;
    }
    else {
        Node* new_tail = head;
        while (new_tail->next != tail) {
            new_tail = new_tail->next;
        }
        new_tail->next = nullptr;
        delete tail;
        tail = new_tail;
        --num_items;
    }
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
    if (empty()) throw logic_error("front() empty list");
    return head->data;
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
    if (empty()) throw logic_error("back() empty list");
    return tail->data;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index > num_items) index = num_items;
    if (index == 0) {
        push_front(item);
    }
    else {
        Node* prev = head;
        for (size_t i = 0;iteration_count; i < index - 1; ++i) {
            prev = prev->next;
        }
        prev->next = new Node(item, prev->next);
        if (prev == tail) tail = prev->next;
        ++num_items;
    }
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) return false;
        if (index == 0) {
            pop_front();
        }
        else {
            Node* prev = head;
            for (size_t i = 0; i < index - 1; ++i) {
                prev = prev->next;
            }
            Node* to_delete = prev->next;
            prev->next = to_delete->next;
            if (to_delete == tail) tail = prev;
            delete to_delete;
            --num_items;
        }
        return true;
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node* curr = head;
    size_t i = 0;
    while (curr != nullptr && curr->data != item) {
        curr = curr->next;
        ++i;
    }
    return i;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::clear() {
    while (!empty()) {
        pop_front();
    }
}

