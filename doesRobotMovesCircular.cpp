string isCircular(string path) 
{
    // complete the function here
    int direction = 0;
    pair<int,int> start = {0,0};
    vector<vector<int>> steps = {{0,1}, {-1,0}, {0,-1}, {1,0}};
    for(char c: path)
    {
        if(c == 'L')
        {
            direction = (direction + 1) % 4;
        }
        else if(c == 'R')
        {
            direction = (direction + 3) % 4;
        }
        else
        {
            start.first += steps[direction][0];
            start.second += steps[direction][1];
        }
    }
    if(start.first == 0 && start.second == 0)
    {
        return "Circular";
    }
    return "Not Circular";
}