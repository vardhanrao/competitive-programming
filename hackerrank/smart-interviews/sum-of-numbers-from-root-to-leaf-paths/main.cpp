#include <fstream>
#include <vector>

using namespace std;
using elem_type = unsigned int;

constexpr const unsigned long mod = 1000000007;

template<typename T, typename R = unsigned long>
class BST {

    using elem_type = T;
    using return_type = R;

public:

    BST(): root(nullptr) {}

    explicit BST(const vector<elem_type> & v): root(nullptr) {
        for(const elem_type & elem : v)
            this->add(elem);
    }

    inline ~BST() {
        delete this->root;
    }

    void add(elem_type elem) {
        if(this->root)
            this->root->add(elem);
        else
            this->root = new BSTNode(elem);
    }

    inline return_type get_sums() const {
        if(!this->root)
            return { static_cast<return_type>(0) };
        return this->root->get_sums();
    }

private:

    struct BSTNode {

        elem_type elem;
        BSTNode *right, *left;

        explicit BSTNode(elem_type t_elem):
                elem(move(t_elem)),
                right(nullptr),
                left(nullptr)
        {}

        inline ~BSTNode() {
            delete this->left, delete this->right;
        }

        void add(elem_type elem) {
            if(elem < this->elem) {
                if(!this->left)
                    this->left = new BSTNode(elem);
                else
                    this->left->add(elem);
            }
            else {
                if(!this->right)
                    this->right = new BSTNode(elem);
                else
                    this->right->add(elem);
            }
        }

        return_type get_sums(return_type curr_value = static_cast<return_type>(0)) const {

            elem_type elem = this->elem;

            while(elem)
                curr_value = (curr_value * 10) % mod, elem /= 10;

            return_type new_value = (curr_value + this->elem) % mod;

            if(!this->left and !this->right)
                return new_value;

            return_type left_result = this->left ? this->left->get_sums(new_value) : static_cast<return_type>(0);
            return_type right_result = this->right ? this->right->get_sums(new_value) : static_cast<return_type>(0);
            return (left_result + right_result) % mod;
        }

    };

    BSTNode * root;
};

int main() {

    unsigned int T, N;
    fstream fin("../input.txt"), fout("../output.txt", ios::out);

    fin >> T;

    while(T--) {
        fin >> N;
        elem_type tmp;
        vector<elem_type> v;
        while(N--)
            fin >> tmp, v.push_back(tmp);
        fout << BST<elem_type>{v}.get_sums() << endl;
    }

    fin.close(), fout.close();

    return 0;
}