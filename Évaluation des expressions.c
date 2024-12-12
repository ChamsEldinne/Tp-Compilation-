int evaluateExpression(int left, int right, char op) {
    switch(op) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
        default: return 0;
    }
}
