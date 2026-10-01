class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n;

        for (int i = 0; i < data.size(); i++) {
            int byte = data[i];

            if ((byte >> 7) == 0) {
                n = 1;
            }
            else if ((byte >> 5) == 0b110) {
                n = 2;
            }
            else if ((byte >> 4) == 0b1110) {
                n = 3;
            }
            else if ((byte >> 3) == 0b11110) {
                n = 4;
            }
            else {
                return false;
            }

            if (i + n > data.size())
                return false;

            for (int j = 1; j < n; j++) {
                if ((data[i + j] >> 6) != 0b10)
                    return false;
            }

            i += n - 1;
        }

        return true;
    }
};