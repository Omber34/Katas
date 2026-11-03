#include <gtest/gtest.h>

namespace
{
    struct LinkedList
    {
        struct Node
        {
            int data;
            Node *next;
        };

        Node *head = nullptr;

        void print() const
        {
            for (const auto *current = head; current != nullptr; current = current->next)
            {
                std::cout << current->data << " ";
            }
            std::cout << std::endl;
        }

        Node *tail() const
        {
            if (head == nullptr)
                return nullptr;
            auto *current = head;
            for (; current->next != nullptr; current = current->next)
            {
                ;
            }
            return current;
        }

        LinkedList(std::initializer_list<int> data)
        {
            if (data.size() == 0)
                return;

            head = new Node{.data = *data.begin()};
            auto *first = head;
            for (auto it = data.begin() + 1; it != data.end(); ++it)
            {
                head->next = new Node{.data = *it};
                head = head->next;
            }
            head = first;
        }

        bool operator==(LinkedList const &other) const
        {
            const Node *current = head;
            const Node *otherCurrent = other.head;

            while (current != nullptr || otherCurrent != nullptr)
            {
                if (current->data != otherCurrent->data)
                    return false;
                current = current->next;
                otherCurrent = otherCurrent->next;
            }

            if (current == nullptr && otherCurrent == nullptr)
                return true;

            return false;
        }
    };

    void reverse(LinkedList &list)
    {
        using Node = LinkedList::Node;
        Node* current = list.head;
        Node* newHead = nullptr;

        while (current != nullptr)
        {

            Node* next = current->next;
            current->next = newHead;
            newHead = current;
            current = next;
        }

        list.head = newHead;
    }
}

TEST(ReverseLinkedList, TrivialTest)
{
    LinkedList list{1, 2, 3, 4, 5};
    const LinkedList reversed{5, 4, 3, 2, 1};
    reverse(list);
    EXPECT_EQ(list, reversed);
}
