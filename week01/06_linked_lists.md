# 6. Linked lists (односвязные списки)

## Идея

Односвязный список состоит из узлов. Каждый узел хранит значение и указатель `next` на следующий узел:

`head -> [value | next] -> [value | next] -> nullptr`

Узлы обычно выделяются отдельно в куче, поэтому они не обязаны лежать рядом в памяти. Доступ по индексу медленный (`O(n)`), зато вставка/удаление после уже известного узла — `O(1)`.

## Минимальная реализация

```cpp
#include <iostream>

struct Node {
    int value;
    Node* next;
    Node(int value, Node* next = nullptr) : value(value), next(next) {}
};

void pushFront(Node*& head, int value) {
    head = new Node(value, head);
}

void print(const Node* head) {
    for (auto* cur = head; cur != nullptr; cur = cur->next)
        std::cout << cur->value << ' ';
    std::cout << '\n';
}

bool eraseFirst(Node*& head, int value) {
    Node** link = &head; // адрес указателя, который ведёт на текущий узел
    while (*link && (*link)->value != value) link = &((*link)->next);
    if (!*link) return false;
    Node* removed = *link;
    *link = removed->next;
    delete removed;
    return true;
}

void clear(Node*& head) {
    while (head) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}
```

`Node*&` позволяет функции изменить сам `head`. После `new` всегда нужен соответствующий `delete`, иначе будет утечка памяти. Нельзя обращаться к узлу после его `delete`.

## Сложности

| Операция | Сложность |
|---|---:|
| вставка в начало | `O(1)` |
| поиск значения | `O(n)` |
| доступ к `i`-му элементу | `O(n)` |
| вставка после известного узла | `O(1)` |
| вставка в конец без `tail` | `O(n)` |

## Разворот списка

Три указателя (`previous`, `current`, `next`) меняют направление ссылок за `O(n)` времени и `O(1)` памяти:

```cpp
Node* reverse(Node* head) {
    Node* previous = nullptr;
    Node* current = head;
    while (current) {
        Node* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}
```

## Запомни

Список хорош, когда важны вставки/удаления и уже есть нужный узел. `vector` лучше, когда нужен быстрый доступ по индексу и cache-friendly память.

## Самопроверка

1. Почему `head` передают по ссылке (`Node*&`) в `pushFront`?
2. Напиши функцию `pushBack` с указателем `tail`.
3. Найди середину списка двумя указателями: `slow` идёт на один шаг, `fast` — на два.
