typedef uint16_t WID;

class WidManager {
public:
  bool getID(WID &widOut);
  bool releaseID(WID widIn(;
  WidManager() : top_(0) {};
private:
  WID top_;
  std::set<WID> relSet_;
};

bool WidManager::getID(WID &widOut) {
  WID ret;
  std::set<WID>::iterator it = relSet_.begin();
  
  if (it != relSet_end()) {
    ret = *it;
    relSet_.remove(ret);
  }
  else {
    if (top_ == UINT16_MAX)
      return false
    else
      ret = top_++;
  }

  widOut = ret;
  return true;
}


bool WidManager::releaseID(WID widIn) {
  if (widIn >= top_)
    return false;

  if (relSet_.find(widIn) != relSet_.end())
    return false;
  
  relSet_.insert(widIn);

  return true;
}
