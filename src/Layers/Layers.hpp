#pragma once 

#include <vector>
#include <string>

#include "../Events/Events.hpp"

namespace Catharsis {
namespace Layers {

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

    class LayerManager {
        public:
            LayerManager() = default;
            ~LayerManager() = default;

            void addLayer(const Layer* layer) {
                m_Layers.emplace_back(layer);
            }

            void removeLayer(int index) {
                if (index >= 0 && index < m_Layers.size()) {
                    m_Layers.erase(m_Layers.begin() + index);
                }
            }

            Layer* getLayer(int index) {
                return m_Layers.at(index);
            }

            size_t getLayerCount() const {
                return m_Layers.size();
            }

            std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
            std::vector<Layer*>::iterator end() { return m_Layers.end(); }
            std::vector<Layer*>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
            std::vector<Layer*>::reverse_iterator rend() { return m_Layers.rend(); }

            std::vector<Layer*>::const_iterator begin() const { return m_Layers.begin(); }
            std::vector<Layer*>::const_iterator end()	const { return m_Layers.end(); }
            std::vector<Layer*>::const_reverse_iterator rbegin() const { return m_Layers.rbegin(); }
            std::vector<Layer*>::const_reverse_iterator rend() const { return m_Layers.rend(); }
        private:
            std::vector<Layer*> m_Layers;


    };
} // namespace Layerss
}// namespace Catharsis
  //
