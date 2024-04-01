#pragma once

#include <string>

#include "LayoutWriter.hpp"
#include "Layout.hpp"

class LayoutWriter_DXF : public LayoutWriter {
public:
  LayoutWriter_DXF();
  virtual ~LayoutWriter_DXF() = default;
public:
  bool Write(const STR_CLASS &fileName, Layout* layout) final;
private:
};

