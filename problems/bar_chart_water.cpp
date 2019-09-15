int barChartWater(vector<int> chart) {
    int prevHigh = 0;
    int totalWater = 0;
  
    vector<int> nextHighs(chart.size());
  
    for (int i=chart.size()-1; i>=0; --i) {
        if (i == chart.size()-1)
            nextHighs[i] = 0;
        else
            nextHighs[i] = max(nextHighs[i+1], chart[i+1]);
    }
  
    for (int i=0; i<chart.size(); ++i) {
        totalWater += min(prevHigh, nextHighs[i]) - chart[i];
        prevHigh = max(prevHigh, chart[i]);
    }

    return totalWater;
}
