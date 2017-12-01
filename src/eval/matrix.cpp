#include "eval/matrix.hpp"

Matrix::Matrix(){}
Matrix::~Matrix(){}

void Matrix::tomatrix(string st)
{
    int _l;
    itstr_t ite;
    itstr_t itb;
    itstr_t rbe;
    itstr_t ren;
    vector<int> len;
    vector<string> m;
    vector<string> ret;
    vector<string> vals;

    _l = 0;
    if (st.find(";") != string::npos)
    {
        m = strsplit(";", st);
        ite = m.end();
        itb = m.begin();
        for (int i = 0; itb != ite; itb++, i++)
            getValues(*itb, vals, i);
    }
    else
    {
        m.push_back(st);
        itb = m.begin();
        getValues(*itb, vals, 0);
    }
    ite = vals.end();
    itb = vals.begin();
    _col_length = vals.size();
    for (int i = 0; i < _col_length; i++, itb++)
    {
        ret = strsplit(",", *itb);
        ren = ret.end();
        rbe = ret.begin();
        _row_length = ret.size();
        for (int j = 0; j < _row_length; j++, rbe++)
            matNN[i][j] = stod(*rbe);
    }
    // ite = vals.end();
    // itb = vals.begin();
    // for (; itb != ite; itb++)
    //     cout << *itb << " ";
    // cout << endl;
}

void Matrix::print_mat()
{
    for (int i = 0; i < _col_length; i++)
    {
        cout << "[";
        for (int j = 0; j < _row_length; j++)
            if (j < _row_length - 1)
                cout << matNN[i][j] << " ";
            else 
                cout << matNN[i][j];
        cout << "]" << endl;
    }
}

void Matrix::getValues(string &m, vector<string> &v, int f)
{
    string mat_str;
    size_t np = m.find("[");
    size_t pe = m.find("]");

    if (f == 0)
        np = m.find("[", np + 1) + 1;
    else np += 1;
    mat_str = m.substr(np, pe - np);
    v.push_back(mat_str);
    // cout << "np: " << np << "\npe: " << pe << "\n" << mat_str << endl;
}

// void Matrix::row(string n, vector<string> &m)
// {
// }