#pragma once

#include <string>

#include "LayoutWriter.hpp"
#include "Layout.hpp"

class LayoutWriter_MSK : public LayoutWriter {
public:
  LayoutWriter_MSK();
  virtual ~LayoutWriter_MSK() = default;
public:
  bool Write(const STR_CLASS &fileName, Layout *layout) final;
private:
};
