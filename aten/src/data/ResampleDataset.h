#ifndef XT_RESAMPLE_DATASET_H
#define XT_RESAMPLE_DATASET_H

#include <string>
#include <vector>
#include <functional>
#include "TensorLib/TensorLib.h"
#include "Dataset.h"

class ResampleDataset : public Dataset
{
public:
   ResampleDataset(Dataset& dataset);
   ResampleDataset(Dataset& dataset, std::vector<uint64_t>& perm);
   ResampleDataset(Dataset& dataset, std::function<uint64_t(uint64_t)> perm);
   virtual void getField(uint64_t idx, std::string& fieldkey, tlib::Tensor& field);
   virtual uint64_t size();
   virtual void resample();
protected:
   std::vector<uint64_t> perm_;
   uint64_t size_;
private:
   Dataset* dataset_;
   std::function<uint64_t(uint64_t)> permfunc_;
   std::vector<tlib::Tensor> fields_;
};

#endif
