#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "string.h"

using namespace std;

/**
 * 语法分析器
 * author: seanlee
 * mail: xmlee97@gmail.com
 */

class Grammar{
private:
	// *** variables ***//
	int maxidx_terminal;	// 下标最大的终结符号下标
	int num_nonterminals;	// 非终结符个数
	int num_rules;	// 自定义语法规则个数
	static int start_symbol;// 开始符号

	// grammar input
	ifstream input; 
	string line;

	vector<string> terminal_names;   // 终结符
	vector<string> nonterminal_names; // 非终结符
	vector<vector<int> > first_sets; // first集
	vector<vector<int> > follow_sets; // follow集
	vector<vector<int> > predict_sets;  // predict集
	vector<vector<int> > parse_table; // 解析表
	vector<vector<int> > full_rules; // 自定义语法规则集
	vector<vector<int> > right_hand_sides; // 结果集对应的右边部分

private:
	// *** private functions ***//
	// 统计grammar
	void _grammar_counter(char* inputFile);
	// 获取 terminal / nonterminal 
	vector<vector<string> > _process_grammar(char* inputFile);
	// 查看symbol是否在数组里
	bool _in_array(vector<int> find_in, int element);
	// 获取symbol的下标
	// 通过symbol获取对应的id，为了区分终结和非终结符，规定终结符id * -1 < 0，非终结符 > 0
	int _get_idx_by_symbol(string symbol_to_find);
	// 元素压栈
	vector<int> _push_unique_elements(vector<int> target, vector<int> source);

public:
	// *** public functions ***//
	Grammar();
	void init(char* inputName);
	void parse();
	void print_table();
	
	// 获取结果集
	vector<vector<int> > get_rule(char* inputFile, vector<bool> &func_is_epsilon);
	// 获取first集
	vector<vector<int> > get_first(vector<bool> local_is_epsilon);
	// 获取follow集
	vector<vector<int> > get_follow(vector<bool> local_is_epsilon, vector<vector<int> > local_first_sets);
	// 获取predict集
	vector<vector<int> > get_predict(vector<bool> local_is_epsilon, vector<vector<int> > local_first_sets, vector<vector<int> > local_follow_sets);
};
