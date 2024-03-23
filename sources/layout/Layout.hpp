#pragma once

#include <string>
#include <vector>

// Used in GDSII
struct Units {
  double  user,
          physical;
};

struct Coord {
  int32_t x,
          y;
};

// Used in GDSII
struct Property {
  int16_t     index;
  std::string value;
};

enum class GeometryType {
  undefined = 0,
  polygon,
  path,
  text,
  rectangle,
  reference,
};

struct Geometry {
  GeometryType          type;
  int16_t               layer;
  Coord                 minCoord,
                        maxCoord;
  std::vector<Property> properties;
  std::vector<Coord>    coords;
public:
  Geometry(GeometryType t) : type(t), layer(-1), minCoord({ INT32_MAX, INT32_MAX }), maxCoord({ INT32_MIN, INT32_MIN }) {}
};

struct Polygon : public Geometry {
  int16_t               dataType;
public:
  Polygon() : Geometry(GeometryType::polygon), dataType(0) {}
};

struct Path : public Geometry {
  int16_t               dataType,
                        pathType;
  int32_t               width;
public:
  Path() : Geometry(GeometryType::path), dataType(0), pathType(0), width(0) {}
};

struct Text : public Geometry {
  int16_t                textType,
                         flagsPresentation,
                         pathType,
                         flagsTransformation;
  double                 magnification;
  int32_t                width;
  std::string            stringValue;
public:
  Text() : Geometry(GeometryType::text), textType(0), flagsPresentation(0), pathType(0), flagsTransformation(0), magnification(1.0), width(0) {}
};

struct Rectangle : public Geometry {
  int16_t                rectType;
public:
  Rectangle() : Geometry(GeometryType::rectangle), rectType(0) {}
};

struct Element;

struct Reference : public Geometry {
  std::string             name;
  Element                *referenceTo;
  int16_t                 transformationFlags;
  double                  magnification;
public:
  Reference() : Geometry(GeometryType::reference), name(""), referenceTo(nullptr), transformationFlags(0), magnification(1.0) {}
};

struct Element {
  bool                    isFlat;
  Coord                   minCoord,
                          maxCoord;
  bool                    nested;
  std::string             name;
  std::vector<Geometry *> geometries;
public:
  Element() : isFlat(true), minCoord({ INT32_MAX, INT32_MAX }), maxCoord({ INT32_MIN, INT32_MIN }), nested(false) {}
  ~Element() {
    for (size_t i = 0; i < geometries.size(); ++i) {
      delete geometries[i];
      geometries[i] = nullptr;
    }
    geometries.clear();
  }
};

struct Layer {
  int16_t                 layer;
  int16_t                 dataType;
  std::string             name;
  std::vector<Geometry *> geometries;
};

struct Library {
  Units                   units;
  Coord                   minCoord,
                          maxCoord;
  std::string             name;
  std::vector<Element *>  elements;
  std::vector<Layer>      layers;
public:
  Library() : units({ 0.001 , 1e-9}), minCoord({ INT32_MAX, INT32_MAX }), maxCoord({ INT32_MIN, INT32_MIN }) {
  }
 ~Library() {
    for (size_t i = 0; i < elements.size(); ++i) {
      delete elements[i];
      elements[i] = nullptr;
    }
    elements.clear();
    layers.clear();
  }
};

enum class FileFormat {
  undefined,
  CIF,
  DXF,
  GDSII_ascii,
  GDSII_bin,
  MAG,
  MSK,
  OASIS,
};

#include "LinuxCompat.hpp"

struct Layout {
  STR_CLASS               fileName;
  FileFormat              fileFormat;
  std::vector<Library *>  libraries;
public:
  ~Layout() {
    Clear();
  }
public:
  void Clear() {
    for (size_t i = 0; i < libraries.size(); ++i) {
      delete libraries[i];
      libraries[i] = nullptr;
    }
    libraries.clear();
  }
};
