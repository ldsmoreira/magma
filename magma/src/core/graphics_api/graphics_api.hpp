namespace magma {
    class GraphicsAPI {
    public:
        virtual ~GraphicsAPI() = default;
        virtual void initialize() = 0;
        virtual void shutdown() = 0;
    };
}