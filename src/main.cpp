#include "VulkanCore/VulkanRenderer.h"

int main() {
    VulkanRenderer renderer;

    try {
        renderer.run();
    } catch (const std::exception& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
