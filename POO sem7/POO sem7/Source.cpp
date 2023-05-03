#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template<typename T>
class TreeNode {
public:
    TreeNode(const T& value) : value_(value), parent_(nullptr) {}

    void add_node(TreeNode<T>* node) {
        node->parent_ = this;
        children_.push_back(node);
    }

    TreeNode<T>* get_node(TreeNode<T>* parent = nullptr) {
        if (!parent) {
            return this;
        }

        for (auto& child : children_) {
            if (child->parent_ == parent) {
                return child;
            }
        }

        return nullptr;
    }

    void delete_node() {
        for (auto& child : children_) {
            child->delete_node();
        }

        if (parent_) {
            parent_->children_.erase(std::remove(parent_->children_.begin(), parent_->children_.end(), this), parent_->children_.end());
        }
    }

    TreeNode<T>* find(std::function<bool(T)> cmp) {
        if (cmp(value_)) {
            return this;
        }

        for (auto& child : children_) {
            auto found = child->find(cmp);
            if (found) {
                return found;
            }
        }

        return nullptr;
    }

    void insert(TreeNode<T>* node, size_t index) {
        if (index >= children_.size()) {
            add_node(node);
            return;
        }

        node->parent_ = this;
        children_.insert(children_.begin() + index, node);
    }

    void sort(std::function<bool(const T&, const T&)> cmp = nullptr) {
        if (cmp) {
            std::sort(children_.begin(), children_.end(), [cmp](auto& a, auto& b) {
                return cmp(a->value_, b->value_);
                });
        }
        else {
            std::sort(children_.begin(), children_.end(), [](auto& a, auto& b) {
                return a->value_ < b->value_;
                });
        }
    }

    size_t count(TreeNode<T>* parent = nullptr) {
        size_t count = 0;

        if (!parent) {
            ++count;
        }

        for (auto& child : children_) {
            count += child->count(parent);
        }

        return count;
    }

    T value_;
    TreeNode<T>* parent_;
    std::vector<TreeNode<T>*> children_;
};

constexpr float operator"" _Kelvin(long double temperature) {
    return static_cast<float>(temperature - 273.15);
}

constexpr float operator"" _Fahrenheit(long double temperature) {
    return static_cast<float>((temperature - 32) * 5 / 9);
}

int main() {
    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;

    std::cout << a << " Celsius" << std::endl;
    std::cout << b << " Celsius" << std::endl;

    return 0;
}