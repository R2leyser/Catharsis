#pragma once 

#include <vector>
#include <string>

#include "../Events/Events.hpp"

namespace Catharsis {
namespace Graphics {

    class Layer { 
        public:
            Layer(const std::string& name) : layerName(name) {}
            std::string getName() const { return layerName; }
            void onRender();
            void onUpdate();

            void onAttach();
            void onDetach();

            void onEvent(Catharsis::Events::Event event);
        private:
            std::string layerName;
    };

    class Layers {
        public:
            Layers() = default;
            ~Layers() = default;

            void addLayer(const Layer& layer) {
                layers.push_back(layer);
            }

            void removeLayer(int index) {
                if (index >= 0 && index < layers.size()) {
                    layers.erase(layers.begin() + index);
                }
            }

            Layer& getLayer(int index) {
                return layers.at(index);
            }

            size_t getLayerCount() const {
                return layers.size();
            }
        private:
            std::vector<Layer> layers;
    };
} // namespace Graphics
}// namespace Catharsis
  //
