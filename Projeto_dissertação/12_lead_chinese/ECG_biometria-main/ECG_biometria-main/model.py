from keras.models import Model
from keras.layers import Input, Dense, Dropout, Conv1D, MaxPooling1D, Flatten, BatchNormalization, Activation
from keras import initializers
from keras import optimizers

def cnn_model(input_dim, num_classes):
    lr = 0.001
    initializer = initializers.random_normal(mean=0.0, stddev=0.01, seed=None)

    input = Input(shape=input_dim, name='Input')

    x = Conv1D(filters=32, kernel_size=14, strides=1, kernel_initializer=initializer, name='Conv1')(input)
    x = BatchNormalization(name='Norm1')(x)
    x = Activation('relu', name='Relu1')(x)
    x = MaxPooling1D(2, strides=2, name='MaxPool1')(x)

    x = Conv1D(filters=64, kernel_size=5, strides=1, kernel_initializer=initializer, name='Conv2')(x)
    x = BatchNormalization(name='Norm2')(x)
    x = Activation('relu', name='Relu2')(x)
    x = MaxPooling1D(2, strides=2, name='MaxPool2')(x)

    x = Conv1D(filters=96, kernel_size=3, strides=1, kernel_initializer=initializer, name='Conv3')(x)
    x = BatchNormalization(name='Norm3')(x)
    x = Activation('relu', name='Relu3')(x)
    x = MaxPooling1D(2, strides=2, name='MaxPool3')(x)

    x = Conv1D(filters=128, kernel_size=3, strides=1, kernel_initializer=initializer, name='Conv4')(x)
    x = BatchNormalization(name='Norm4')(x)
    x = Activation('relu', name='Relu4')(x)
    x = MaxPooling1D(2, strides=2, name='MaxPool4')(x)

    x = Flatten()(x)

    x = Dense(1028, name='FC1')(x)
    x = Dense(128, name='FC2')(x)
    x = BatchNormalization(name='Norm5')(x)
    x = Dense(num_classes, name='FC3')(x)
    x = Dropout(0.1, name='Dropout')(x)
    x = Activation('softmax', name='Softmax')(x)

    model = Model(inputs=input, outputs=x)
    #model.summary()

    sgd = optimizers.SGD(momentum=0.9)
    model.compile(optimizer=sgd, loss='categorical_crossentropy', metrics=['accuracy'])

    return model

cnn_model(input_dim=(300,1), num_classes=10)