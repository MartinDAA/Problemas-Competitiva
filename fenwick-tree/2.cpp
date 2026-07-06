#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BIT {
    vector<int> bit;
public:
    BIT() {}
    BIT(const vector<int>& nums) {
        int size = nums.size();
        bit.assign(size + 1, 0);
        for (int i = 0; i < size; ++i) {
            bit[i + 1] = nums[i];
        }
        for (int idx = 1; idx <= size; ++idx) {
            int parent = idx + (idx & (-idx));
            if (parent <= size) {
                bit[parent] += bit[idx];
            }
        }
    }
    int getSum(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & (-idx))
            sum += bit[idx];
        return sum;
    }
    void addValue(int idx, int val) {
        for (; idx < bit.size(); idx += idx & (-idx))
            bit[idx] += val;
    }
};

class NumArray {
    BIT bit;
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        this->bit = BIT(nums);
    }
    void update(int index, int val) {
        int diff = val - nums[index]; 
        bit.addValue(index + 1, diff); 
        nums[index] = val; 
    }
    int sumRange(int left, int right) {
        return bit.getSum(right + 1) - bit.getSum(left);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_comandos;
    if (!(cin >> num_comandos)) return 0;

    vector<string> comandos(num_comandos);
    for (int i = 0; i < num_comandos; ++i) {
        cin >> comandos[i];
    }

    NumArray* numArray = nullptr;
    vector<string> output;

    for (const string& cmd : comandos) {
        if (cmd == "NumArray") {
            int tamano_arreglo;
            cin >> tamano_arreglo;
            vector<int> inicial_nums(tamano_arreglo);
            for (int i = 0; i < tamano_arreglo; ++i) {
                cin >> inicial_nums[i];
            }
            numArray = new NumArray(inicial_nums);
            output.push_back("null");
        } 
        else if (cmd == "sumRange") {
            int left, right;
            cin >> left >> right;
            if (numArray) {
                output.push_back(to_string(numArray->sumRange(left, right)));
            }
        } 
        else if (cmd == "update") {
            int index, val;
            cin >> index >> val;
            if (numArray) {
                numArray->update(index, val);
                output.push_back("null");
            }
        }
    }

    cout << "[";
    for (size_t i = 0; i < output.size(); ++i) {
        cout << output[i] << (i == output.size() - 1 ? "" : ", ");
    }
    cout << "]\n";

    delete numArray;
    return 0;
}