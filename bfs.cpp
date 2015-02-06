// BFS求最短路径，或者需要区分层数时
// 通过两个Queue来实现，一个current_queue, 一个next_queue

vector<vector<int> > levelOrder(TreeNode *root) {
	queue<TreeNode *>current_level;
	queue<TreeNode *>next_level;
	TreeNode * temp;
	vector<int> current_vector;
	vector<vector<int> > result;
	if(root == NULL)
		return result;
	current_level.push(root);
	while(!current_level.empty()){
		temp = current_level.front();
		current_level.pop();
		current_vector.push_back(temp->val);
		if(temp->left)
			next_level.push(temp->left);
		if(temp->right)    
			next_level.push(temp->right);
		if(current_level.empty()){
			swap(current_level, next_level); //比较巧妙的操作
			result.push_back(current_vector);//level++什么的就可以了
			current_vector.clear();
		}
	}
	return result;

}